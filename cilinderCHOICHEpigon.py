import cv2
import numpy as np
import serial, time
def firstMovement():
    serialSend("N",5000)
    time.sleep(5)
    print("first movement done")

     
def serialSend(comando ,durata):
    #
    #connessione Arduino-RPi tramite pota USB
    #
    if arduino.isOpen():
        try:
            cmd = comando + " " + str(durata)
            
            arduino.write(cmd.encode())
            print("comando inviato: ",comando)
        except KeyboardInterrupt:
            print("KeyboardInterrupt has been caught.")
    else:
        print("arduino not open")

def cilinderdetect():
    video=True
    cap = cv2.VideoCapture(0)
    net = cv2.dnn.readNetFromONNX("/home/pigeon/yolov5/lestv6.onnx")
    file = open("/home/pigeon/yolov5/classi.txt","r")
    classes = file.read().split('\n')
    focal = 664.08
    realwidth = 4.975
    
    img = cap.read()[1]
    if img is None:
        retun
    img = cv2.resize(img, (1000,600))
    blob = cv2.dnn.blobFromImage(img,scalefactor= 1/255,size=(640,640),mean=[0,0,0],swapRB= True, crop= False)
    net.setInput(blob)
    detections = net.forward()[0]


    # cx,cy , w,h, confidence, 80 class_scores
    # class_ids, confidences, boxes

    classes_ids = []
    confidences = []
    boxes = []
    rows = detections.shape[0]
    centri=[-1]

    cx1=0
    cw=0

    img_width, img_height = img.shape[1], img.shape[0]
    x_scale = img_width/640
    y_scale = img_height/640

    for i in range(rows):
        row = detections[i]
        confidence = row[4]
        if confidence > 0.7:
            classes_score = row[5:]
            ind = np.argmax(classes_score)
            if classes_score[ind] > 0.7:
                classes_ids.append(ind)
                confidences.append(confidence)
                cx, cy, w, h = row[:4]
                x1 = int((cx-w/2)*x_scale)
                y1 = int((cy-h/2)*y_scale)
                
                width = int(w * x_scale)
                height = int(h * y_scale)
                box = np.array([x1,y1,width,height])
                boxes.append(box)

    indices = cv2.dnn.NMSBoxes(boxes,confidences,0.5,0.5)

    closest=2000
    index=1
    for i in indices:
        x1,y1,w,h = boxes[i]
        dist = (realwidth*focal)/w
        label = classes[classes_ids[i]]
        conf = confidences[i]
        text = label + "{:.2f}".format(conf)

        #print(indices.shape,"  " ,indices, "  " , i, "x: ", x1, "y: ", y1)
        cv2.rectangle(img,(x1,y1),(x1+w,y1+h),(255,255,255),2)
        cv2.putText(img, text, (x1,y1-2),cv2.FONT_HERSHEY_COMPLEX, 0.7,(255,0,255),2)
        cv2.putText(img, str(dist), (x1,y1-2+h),cv2.FONT_HERSHEY_COMPLEX, 0.7,(255,0,255),2)
        # print("CENTRO ", centri[len(centri)-1], " ", w)
        print("-------------------------------------------------------------------------------")
        print(index)
        print("X1 ",x1)
        
        print("width", w)
        
        print("checking center at ", (x1+(w/2)))
        
        print("distance from center: ",abs(500-x1+(w/2)))
        if(abs(500-x1+(w/2))<closest):
            closest=abs(320-x1+(w/2))
            cx1=x1
            cdist=dist
            cw=w
        
        index = index+1

    if(closest!=2000):
        print("closest found: ",closest)
        precision=55
        if(cx1+(cw/2)<500-precision):
                serialSend("E",closest/0.3)
                time.sleep(closest/0.3/100)
        elif(cx1+(cw/2)>500+precision):
                serialSend("O",closest/0.3 )
                time.sleep(closest/0.3/100)
        elif(cx1+(cw/2)<500+precision and cx1+(cw/2)>500-precision):
                serialSend("N",150)
                time.sleep(0.5)
                if(dist<16):
                    serialSend("Chiudi",0)
    else:
        print("no cilindro found")
    if video:
        cv2.imshow("VIDEO",img)
        k = cv2.waitKey(10)
        if k == ord('q'):
            cap.release()
            return
#start=input()
#if(start!=""): serialSend("InizioTimer")
with serial.Serial("/dev/ttyACM0", 9600, timeout=1) as arduino:
    time.sleep(3) # wait for serial to open
    if arduino.isOpen():
        print("{} connected!".format(arduino.port))
        
    firstMovement()
    serialSend("Apri",0)
    
    for i in range (100):
        print("photo number:")
        print(i)
        cilinderdetect()
        

