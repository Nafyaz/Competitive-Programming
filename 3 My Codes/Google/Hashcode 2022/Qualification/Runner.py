import subprocess
import os

infolder = 'input_data'
outfolder = "Output"
exeFile = "masum vai 2.exe"

files = os.listdir(infolder)
files = sorted(files)
for i in range(0,len(files)):

    inPath = files[i]
    fin = open(infolder+'/'+inPath,"r")
    fout = open(outfolder+'/'+inPath,"w")
    ferr = open(outfolder+'/err.txt',"w")
    print("Test: "+inPath)
    s = subprocess.run(args='.\\',executable=exeFile,stdin=fin,stdout=fout, stderr=ferr)
    print ("Return Code: ", s.returncode)
    #fin.close()
    fout.flush()
    fout.close()
    ferr.flush()
    ferr.close()



    


    