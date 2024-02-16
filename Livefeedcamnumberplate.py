import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.utils import shuffle
from skimage import io

def recreate_image(codebook, labels, w, h):
    """Recreate the quantized image from the code book and labels."""
    d = codebook.shape[1]
    image = np.zeros((w, h, d))
    label_idx = 0
    for i in range(w):
        for j in range(h):
            image[i][j] = codebook[labels[label_idx]]
            label_idx += 1
    return image

# Load an image
image_url = 'https://images.unsplash.com/photo-1574158622682-e40e69881006'
image = io.imread(image_url)
image = np.array(image, dtype=np.float64) / 255

# Get the dimensions of the image
w, h, d = tuple(image.shape)

# Reshape the image to a 2D array of pixels
image_array = np.reshape(image, (w * h, d))

# Fit the K-means model on a small sub-sample of the data
image_array_sample = shuffle(image_array, random_state=42)[:1000]
kmeans = KMeans(n_clusters=32, random_state=42).fit(image_array_sample)

# Predict the cluster assignments for all pixels
labels = kmeans.predict(image_array)

# Recreate the quantized image
quantized_image = recreate_image(kmeans.cluster_centers_, labels, w, h)

# Display the original and quantized images
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(10, 5), sharex=True, sharey=True)
ax1.imshow(image)
ax1.set_title('Original Image')
ax1.axis('off')

ax2.imshow(quantized_image)
ax2.set_title('Quantized Image (32 colors)')
ax2.axis('off')

plt.show()


