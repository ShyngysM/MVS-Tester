import pandas as pd                                         
import matplotlib.pyplot as plt

# scaling the time axis 1000 = ms
SCALE = 1000
ADC_RES = 2**16
REF_VOLTAGE = 3.3

#### DATA PREPARATION #### 
data_MCU = pd.read_csv('tmp_data.txt',sep=',',header=None)          

df_mcu = pd.DataFrame(data_MCU)                                        

# split dataframes
analog_df = df_mcu

# resolving axis from row integers to human readable data
# µCU
last_analog = analog_df[0].iloc[-1]
time = (analog_df[0]*SCALE/(last_analog+1))
voltage = (analog_df[1]*REF_VOLTAGE/ADC_RES)


#### Plots #### 

fig, axs = plt.subplots(1)
fig.suptitle("Comparison of sampled data: OSZI vs µCU")

axs.plot(time, voltage, color="red", label="MVS Signal (µCU)")
axs.set_ylabel("U [V]")
axs.set_xlabel("t [ms]")


# Platzierung von der Legende
axs.legend(loc = 0)                                                     

plt.show()
