import cv2
import imutils
from imutils.video import VideoStream
from detect_emotion import detect_emotion

vs = VideoStream(src=0).start()

while True:
    frame = vs.read()
    (locs, preds) = detect_emotion(frame)
    frame = imutils.resize(frame, width=400)
    for (box, pred) in zip(locs, preds):
        (startX, startY, endX, endY) = box
        index = preds[0].index(max(preds[0]))
        cv2.putText(frame, "happy", (startX, startY - 10),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.45, (0,255,0), 2)
        cv2.rectangle(frame, (startX, startY), (endX, endY), (0,255,0), 2)
    cv2.imshow("Frame", frame)
    key = cv2.waitKey(1) & 0xFF
    if key == ord("q"):
        break
cv2.destroyAllWindows()
vs.stop()