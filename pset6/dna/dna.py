import csv
from sys import argv
import re

# Check command-line arguments
if len(argv) != 3:
    print("Missing Command line argument.")


# Open text file                                                                                         #Implementation 3
with open(argv[2], "r") as f:
    sequence = f.read()
    #print(sequence)




#print(di.items())


        # Check if STR matches tha data
        # Convert string into int
        # Skip the first column in csv file









# Compute longest run of STR sequence

di = dict()

res = max(re.findall('((?:' + re.escape('AGATC') + ')*)', sequence), key = len)
res1 = max(re.findall('((?:' + re.escape('AATG') + ')*)', sequence), key = len)
res2 = max(re.findall('((?:' + re.escape('TATC') + ')*)', sequence), key = len)

s1 = (res.count('AGATC'))
s2 = (res1.count('AATG'))
s3 = (res2.count('TATC'))

di['AGATC'] = s1
di['AATG'] = s2
di['TATC'] = s3


#print(di)

# Open csv file
with open(argv[1], "r") as file:
    database = csv.DictReader(file)
    # next(database)
    for row in database:
        print(row)
        if int(row['AGATC']) == di['AGATC'] and int(row['AATG']) == di['AATG'] and int(row['TATC']) == di['TATC'] :
            print(row['name'])



