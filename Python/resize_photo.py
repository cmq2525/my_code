import cv2
from PIL import Image
input_path = "/Users/cmq2525/Desktop/zjz.jpeg"
output_path = "/Users/cmq2525/Desktop/zjz_2_inch.jpeg"
img = cv2.imread(input_path)
# 1 inch 358,441
# 2 inch 413 629
img_resize = cv2.resize(img, (413, 626))
cv2.imwrite(output_path, img_resize)
# adjust dpi
im = Image.open(output_path)
im.save(output_path, dpi=(300,300))