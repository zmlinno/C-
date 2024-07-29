# model.py
# import tensorflow as tf
# from tensorflow.keras.models import Sequential
# from tensorflow.keras.layers import Dense
# import numpy as np

# # 创建一个简单的模型
# model = Sequential([
#     Dense(64, activation='relu', input_shape=(4,)),
#     Dense(64, activation='relu'),
#     Dense(1, activation='sigmoid')
# ])

# model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# # 生成一些随机数据进行训练
# X = np.random.random((1000, 4))
# y = np.random.randint(2, size=(1000, 1))

# model.fit(X, y, epochs=10)

# # 保存模型
# model.save('model.h5')

# # 定义预测函数
# def predict(input_data):
#     input_data = np.array(input_data).reshape((1, -1))
#     prediction = model.predict(input_data)
#     return prediction.tolist()


print("hello world")