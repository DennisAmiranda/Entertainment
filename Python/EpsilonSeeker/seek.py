import numpy as np
def StringMatching(prefix, text):
    p_length = len(prefix)
    t_length = len(text)
    dp = np.zeros((p_length+1, t_length+1))
    for i in range(0, p_length+1):
        dp[i][0]=i
    
    
    for i in range(1, p_length+1):
        for j in range(1, t_length+1):
            delta = 1
            if(prefix[i-1] == text[j-1]):
                delta = 0
                
            t = dp[i-1][j-1] + delta
            t = min(dp[i-1][j]+1, t)
            t = min(dp[i][j-1]+1, t)
            dp[i][j]=t 
    mn = 0
    epsilon = dp[p_length][0]
    for j in range(1, t_length):
        if dp[p_length][j] < epsilon:
            epsilon = dp[p_length][j]
            mn = j
            
    return epsilon

print("Hello, this is EpsilonSeeker, a cli that uses stringmatching")
print("Please, insert your string here")
input_string = input(">>>")


words_txt = []
with open("D:\\code\\Python\\EpsilonSeeker\\words.txt", "r") as fl:
    for line in fl:
        words_txt.append(line)
recommend = ""
k = 50
temp = 0

for i in words_txt:
    temp = StringMatching(input_string, i)
    if temp < k:
        k = temp
        recommend = i
        
if(recommend.split() == input_string.split()):
    print("Your string is exact!")
else:
    print("Sorry, an error was detected:")
    print("Input:", input_string)
    print("Fixed:", recommend)
