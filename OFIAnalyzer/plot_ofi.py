import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("ofi_output.csv")

plt.figure(figsize=(12, 6))

plt.subplot(2, 1, 1)
plt.plot(df['timestamp'], df['OFI'], label='OFI', color='green')
plt.title('Order Flow Imbalance (OFI)')
plt.ylabel('OFI')

plt.subplot(2, 1, 2)
plt.plot(df['timestamp'], df['MidPrice'], label='Mid Price', color='blue')
plt.title('Mid Price Over Time')
plt.xlabel('Timestamp')
plt.ylabel('Price')

plt.tight_layout()
plt.show()