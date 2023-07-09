# encoding=utf-8
import serial
import time

if __name__ == '__main__':
    com = serial.Serial('COM5', 115200)
    over_time = 10000000000
    start_time = time.time()

    while True:
        end_time = time.time()
        f = open("hello1.txt", 'a')
       
       
        if end_time - start_time < over_time:
            data = com.read(67)
            data = str(data)
            if data != '':
                print(data)
                f.write(data + "\n")
                f.flush()