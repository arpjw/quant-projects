import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("simulation_log.csv")

plt.figure(figsize=(12, 6))

plt.subplot(2, 2, 1)
plt.plot(df['Step'], df['PnL'], label='PnL', color='green')
plt.title('PnL Over Time')
plt.xlabel('Step'); plt.ylabel('PnL')

plt.subplot(2, 2, 2)
plt.plot(df['Step'], df['Asset'], label='Asset Price')
plt.title('Asset Price Over Time')
plt.xlabel('Step'); plt.ylabel('Price')

plt.subplot(2, 2, 3)
plt.plot(df['Step'], df['Delta'], label='Delta')
plt.plot(df['Step'], df['Gamma'], label='Gamma')
plt.title('Delta & Gamma')
plt.xlabel('Step'); plt.legend()

plt.subplot(2, 2, 4)
plt.plot(df['Step'], df['Option'], label='Option Price', color='orange')
plt.title('Option Price')
plt.xlabel('Step'); plt.ylabel('Option Value')

plt.tight_layout()
plt.show()