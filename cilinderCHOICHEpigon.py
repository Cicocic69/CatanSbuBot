import cv2
import numpy as np
import serial, time
def firstMovement():
    serialSend("N")
    time.sleep(1.5)
    serialSend("Stop")
    print("first movement done")

     
def serialSend(comando):
    #
    #connessione Arduino-RPi tramite pota USB
    #
    if arduino.isOpen():
        try:
            cmd = comando
            print("comando inviato: ",comando)
            arduino.write(cmd.encode())
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


    img_width, img_height = img.shape[1], img.shape[0]
    x_scale = img_width/640
    y_scale = img_height/640

    for i in range(rows):
        row = detections[i]
        confidence = row[4]
        if confidence > 0.5:
            classes_score = row[5:]
            ind = np.argmax(classes_score)
            if classes_score[ind] > 0.5:
                classes_ids.append(ind)
                confidences.append(confidence)
                cx, cy, w, h = row[:4]
                x1 = int((cx-w/2)*x_scale)
                y1 = int((cy-h/2)*y_scale)
                cx1=int(cx)
                centri.append(cx1)
                width = int(w * x_scale)
                height = int(h * y_scale)
                box = np.array([x1,y1,width,height])
                boxes.append(box)

    indices = cv2.dnn.NMSBoxes(boxes,confidences,0.5,0.5)

    closest=2000
    index=1
    for i in indices:
        x1,y1,w,h = boxes[i]
        dist = str((realwidth*focal)/w)
        label = classes[classes_ids[i]]
        conf = confidences[i]
        text = label + "{:.2f}".format(conf)

        #print(indices.shape,"  " ,indices, "  " , i, "x: ", x1, "y: ", y1)
        cv2.rectangle(img,(x1,y1),(x1+w,y1+h),(255,255,255),2)
        cv2.putText(img, text, (x1,y1-2),cv2.FONT_HERSHEY_COMPLEX, 0.7,(255,0,255),2)
        cv2.putText(img, dist, (x1,y1-2+h),cv2.FONT_HERSHEY_COMPLEX, 0.7,(255,0,255),2)
        # print("CENTRO ", centri[len(centri)-1], " ", w)
        print("-------------------------------------------------------------------------------")
        print(index)
        print("X1")
        print(x1)
        print("width")
        print(w)
        print("checking ")
        print(x1+(w/2))
        if(abs(500-x1+(w/2))<closest):
            closest=abs(320-x1+(w/2))
        
        index = index+1
        if video:
            cv2.imshow("VIDEO",img)
            k = cv2.waitKey(10)
            if k == ord('q'):
                return
          
    print("closest found: ")
    print(closest)
    precision=20
    if(x1+(w/2)<500-precision):
            serialSend("O")
    elif(x1+(w/2)>500+precision):
            serialSend("E")
    elif(x1+(w/2)<500+precision and x1+(w/2)>500-precision):
            serialSend("Stop") 
#start=input()
#if(start!=""): serialSend("InizioTimer")
with serial.Serial("/dev/ttyACM0", 9600, timeout=1) as arduino:
    time.sleep(0.1) # wait for serial to open
    firstMovement()
    for i in range (30):
        print("photo number:")
        print(i)
        cilinderdetect()
        #time.sleep(1.50)
