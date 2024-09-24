#!/usr/bin/env python

import argparse
import pandas as pd
import matplotlib.pyplot as plt
import os.path

# ANSI escape codes for colored output
class TerminalColors:
    GREEN = '\033[92m'
    BLUE = '\033[94m'
    RED = '\033[91m'
    ORANGE = '\033[38;5;208m'
    ENDC = '\033[0m'

def load_data(input_file):
    if not os.path.isfile(input_file):
        raise FileNotFoundError("Input file '{}' not found.".format(input_file))
    
    try:
        read_file = pd.read_csv(input_file, sep=',', skiprows=102)
        return read_file
    except Exception as e:
        raise RuntimeError("Error reading input file: {}".format(str(e)))

def plot_data(df, input_file):
    SCALE = 1000
    try:
        dfnum = df.apply(pd.to_numeric, errors='coerce')
        nan = dfnum.isna().sum()[dfnum.isna().sum()>0]
        if nan.any() == True:
            print(f"{TerminalColors.ORANGE}Warning: {TerminalColors.ENDC}" + f"Missing values in following columns: \n{nan}")

        last_digital = dfnum.iloc[-1,0]
        time = (dfnum.iloc[:,0]*SCALE/(last_digital+1))

        fig, axs = plt.subplots(1)
        fig.suptitle('Plot from file: {}'.format(input_file))

        axs.plot(time, dfnum.iloc[:,1], color="blue", label="MVS Signal \n (µC - digitalized)")
        axs.set_xlabel("t [ms]")
        axs.set_ylabel("U_i (0, 1)")

        axs.legend(loc = 0)                                                     
        # plt.figtext(0.7, 0.17, info, ha="center", fontsize=7, bbox={"facecolor":"orange", "alpha":0.5, "pad":5})
        plt.title('Digitalized signal of last measurement')
        plt.show()
        print(f"{TerminalColors.GREEN}PLOT SUCCEDED{TerminalColors.ENDC}")


    except Exception as e:
        raise RuntimeError("Error plotting data: {}".format(str(e)))

def main():
    # parser = argparse.ArgumentParser(description="Plot data from a .dat file.")
    parser = argparse.ArgumentParser(description="Plot data from a .csv file.",
                                     epilog="BB Schneider Test")
    parser.add_argument('-i', '--input', type=str, help="Input file (.csv)", required=True)
    args = parser.parse_args()

    input_file = args.input

    try:
        df = load_data(input_file)
        
        plot_data(df, input_file)

    except Exception as e:
        print(f"{TerminalColors.RED}An error occurred: {TerminalColors.ENDC}" + str(e))


if __name__ == "__main__":
    main()
