import pandas as pd
import matplotlib.pyplot as plt

# scaling the time axis 1000 = ms
SCALE = 1000

data_MCU = pd.read_csv('mvs01.csv',sep=',', skiprows=102)


digital_df = pd.DataFrame(data_MCU)                                        

last_digital = digital_df.iloc[-1,0]
time = (digital_df.iloc[:,0]*SCALE/(last_digital+1))

# info = meas_df.iloc[0,0] + "\n" + meas_df.iloc[1,0]

fig, axs = plt.subplots(1)
fig.suptitle("Plot of sampled data")

axs.plot(time, digital_df.iloc[:,1], color="blue", label="MVS Signal \n (µCU - digitalized)")
axs.set_xlabel("t [ms]")
axs.set_ylabel("U_i (0, 1)")

axs.legend(loc = 0)                                                     
# plt.figtext(0.7, 0.17, info, ha="center", fontsize=7, bbox={"facecolor":"orange", "alpha":0.5, "pad":5})
plt.show()
