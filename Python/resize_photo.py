import cv2
input_path = "/Users/cmq2525/Desktop/zjz.jpeg"
output_path = "/Users/cmq2525/Desktop/zjz_2_inch.jpeg"
img = cv2.imread(input_path)
img_resize = cv2.resize(img, (413, 626))
cv2.imwrite(output_path, img_resize)