import cv2
import numpy as np

cap = cv2.VideoCapture(0)
net = cv2.dnn.readNetFromONNX(r"C:\Users\pigeon\Downloads\yolov5-master\yolov5-master\lestv6.onnx")
file = open(r"C:\Users\pigeon\Downloads\yolov5-master\yolov5-master\classi.txt","r")
classes = file.read().split('\n')
focal = 105.3
realwidth = 50


while True:
    img = cap.read()[1]
    if img is None:
        break
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
    centri=[10,10,10]
    

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
                x1 = int((cx- w/2)*x_scale)
                y1 = int((cy-h/2)*y_scale)
                cx1=int(cx)
                centri.append(cx1)
                width = int(w * x_scale)
                height = int(h * y_scale)
                box = np.array([x1,y1,width,height])
                boxes.append(box)

    indices = cv2.dnn.NMSBoxes(boxes,confidences,0.5,0.5)

    for i in indices:
        x1,y1,w,h = boxes[i]
        dist = str((realwidth*focal)/w)
        label = classes[classes_ids[i]]
        conf = confidences[i]
        text = label + "{:.2f}".format(conf)
        
        #print(indices.shape,"  " ,indices, "  " , i, "x: ", x1, "y: ", y1)
        cv2.rectangle(img,(x1,y1),(x1+w,y1+h),(255,0,0),2)
        cv2.putText(img, text, (x1,y1-2),cv2.FONT_HERSHEY_COMPLEX, 0.7,(255,0,255),2)
        cv2.putText(img, dist, (x1,y1-2+h),cv2.FONT_HERSHEY_COMPLEX, 0.7,(255,0,255),2)
    print("CENTRO ", centri[len(centri)-1])
    if(centri[len(centri)-1]<310):
            print("gira a sinistra")
    else:
        if(centri[len(centri)-1]>330):
            
            print("gira a destra")
        else:
            print("quanto è vicino? sei al centro")
    
    cv2.imshow("VIDEO",img)
    k = cv2.waitKey(10)
    if k == ord('q'):
        break
    
    
