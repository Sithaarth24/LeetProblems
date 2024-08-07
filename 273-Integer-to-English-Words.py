Ones = [\One\,\Two\,\Three\,\Four\,\Five\,\Six\,\Seven\,\Eight\,\Nine\,\\]
Tens = [\Ten\,\Twenty\,\Thirty\,\Forty\,\Fifty\,\Sixty\,\Seventy\,\Eighty\,\Ninety\,\\]
Specials = [\Eleven\,\Twelve\,\Thirteen\,\Fourteen\,\Fifteen\,\Sixteen\,\Seventeen\,\Eighteen\,\Nineteen\,\Ten\]
Highers = [\Thousand\,\Million\,\Billion\,\Trillion\]

def fun(temp, f):
    if(temp[0] == '0' and temp[1] == \0\ and temp[2] == '0'):
        return \\
    s = \\
    if(len(temp) == 3):
        if(temp[0] != '0'):
            if(temp[1] != '1'):
                s = Ones[int(temp[0]) -1] + \ Hundred \ + Tens[int(temp[1]) -1] + \ \ + Ones[int(temp[2]) - 1]
            else:
                s = Ones[int(temp[0]) -1] + \ Hundred \ + Specials[int(temp[2]) -1]
        else:
            if(temp[1] != '1'):
                s = Ones[int(temp[0]) -1] + \ \ + Tens[int(temp[1]) -1] + \ \ + Ones[int(temp[2]) - 1]
            else:
                s = Ones[int(temp[0]) -1] + \ \ + Specials[int(temp[2]) -1]
    elif(len(temp) == 2):
        if(temp[0] != '1'):
            if(temp[1] != '0'):
                s = Tens[int(temp[0]) -1] + \ \ + Ones[int(temp[1]) - 1]
            else:
                s = Tens[int(temp[0]) - 1]
        else:
            s = Specials[int(temp[1]) -1]
    else:
        s = Ones[int(temp[0]) - 1]
    if(f == 0):
        return s
    return s + \ \ + Highers[f-1] + \ \

class Solution:    
    def numberToWords(self, num: int) -> str:
        if(num == 0):
            return \Zero\
        res = \\
        c = 0
        temp = \\
        c1 = 0
        while(num):
            if(c == 3):
                c = 0
                res = fun(temp,c1) + res
                c1+=1
                temp = \\

            temp = str(num%10) + temp
            num=num//10
            c+=1
        res = fun(temp,c1) + res
        return \ \.join(list(res.split())).rstrip()
        