import cv2

image = cv2.imread('download.jpeg')
print(image.shape)
height,width = image.shape[:2]

mid_x = width // 2
mid_y = height // 2

top_left = image[0:mid_y, 0:mid_x]
top_right = image[0:mid_y, mid_x:width]
bottom_left = image[mid_y:height, 0:mid_x]
bottom_right = image[mid_y:height, mid_x:width]

cv2.imshow('Top left quadrant', top_left)
cv2.imshow('Top right quadrant', top_right)
cv2.imshow('Bottom left quadrant', bottom_left)
cv2.imshow('Bottom right quadrant', bottom_right)

cv2.waitKey(0) 
cv2.destroyAllWindows()
