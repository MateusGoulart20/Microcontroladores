import cv2
import urllib.request
import numpy as np
 
def nothing(x):
    pass
 
url='http://192.168.148.131/cam-lo.jpg'
##'''cam.bmp / cam-lo.jpg /cam-hi.jpg / cam.mjpeg '''
cv2.namedWindow("live transmission", cv2.WINDOW_AUTOSIZE)

#Defina os valores de limite inferior e superior para a cor azul no espaço HSV
l_h_blue, l_s_blue, l_v_blue = 92, 57, 50
u_h_blue, u_s_blue, u_v_blue = 142, 153, 178

# Defina os valores de limite inferior e superior para a cor verde no espaço HSV
l_h_green, l_s_green, l_v_green = 40, 40, 40
u_h_green, u_s_green, u_v_green = 80, 255, 255

# Defina os valores de limite inferior e superior para a cor vermelha no espaço HSV
l_h_red, l_s_red, l_v_red = 0, 100, 100
u_h_red, u_s_red, u_v_red = 10, 255, 255

#l_h, l_s, l_v = 92, 57, 50
#u_h, u_s, u_v = 142, 153, 178
 
while True:
    img_resp=urllib.request.urlopen(url)
    imgnp=np.array(bytearray(img_resp.read()),dtype=np.uint8)
    frame=cv2.imdecode(imgnp,-1)
    #_, frame = cap.read()
    
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
 
#    l_b = np.array([l_h, l_s, l_v])
#    u_b = np.array([u_h, u_s, u_v])    
#    mask = cv2.inRange(hsv, l_b, u_b)
#    cnts, _ = cv2.findContours(mask,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

# Crie máscaras para cada cor
    mask_blue = cv2.inRange(hsv, np.array([l_h_blue, l_s_blue, l_v_blue]), np.array([u_h_blue, u_s_blue, u_v_blue]))
    mask_green = cv2.inRange(hsv, np.array([l_h_green, l_s_green, l_v_green]), np.array([u_h_green, u_s_green, u_v_green]))
    mask_red = cv2.inRange(hsv, np.array([l_h_red, l_s_red, l_v_red]), np.array([u_h_red, u_s_red, u_v_red]))

 # Combine as máscaras
    #combined_mask = cv2.bitwise_or(mask_blue, cv2.bitwise_or(mask_green, mask_red))

    # Encontre contornos na máscara combinada
    #cnts, _ = cv2.findContours(combined_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    cnts_blue, _ = cv2.findContours(mask_blue, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)


    for c in cnts_blue:
        area=cv2.contourArea(c)
        if area>2000:
            cv2.drawContours(frame,[c],-1,(255,0,0),3)
            M=cv2.moments(c)
            cx=int(M["m10"]/M["m00"])
            cy=int(M["m01"]/M["m00"])
 
            cv2.circle(frame,(cx,cy),7,(255,255,255),-1)
            cv2.putText(frame,"blue",(cx-20, cy-20),cv2.FONT_HERSHEY_SIMPLEX, 1, (0,0,255),2)

    # Encontre contornos na máscara verde
    cnts_green, _ = cv2.findContours(mask_green, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    for c in cnts_green:
        area = cv2.contourArea(c)
        if area > 2000:
            cv2.drawContours(frame, [c], -1, (0, 255, 0), 3)
            M = cv2.moments(c)
            cx = int(M["m10"] / M["m00"])
            cy = int(M["m01"] / M["m00"])

            cv2.circle(frame, (cx, cy), 7, (255, 255, 255), -1)
            cv2.putText(frame, "green", (cx - 20, cy - 20), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
    
    # Encontre contornos na máscara vermelha
    cnts_red, _ = cv2.findContours(mask_red, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    for c in cnts_red:
        area = cv2.contourArea(c)
        if area > 2000:
            cv2.drawContours(frame, [c], -1, (0, 0, 255), 3)
            M = cv2.moments(c)
            cx = int(M["m10"] / M["m00"])
            cy = int(M["m01"] / M["m00"])

            cv2.circle(frame, (cx, cy), 7, (255, 255, 255), -1)
            cv2.putText(frame, "red", (cx - 20, cy - 20), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)







    #res = cv2.bitwise_and(frame, frame, mask=mask_red)
 
    cv2.imshow("live transmission", frame)
    #cv2.imshow("mask", mask_red)
    #cv2.imshow("res", res)
    key=cv2.waitKey(5)
    if key==ord('q'):
        break
    
 
cv2.destroyAllWindows()