from subprocess import PIPE, run
import subprocess
import random


def createInput():
    n = random.randint(5, 20000)
    tmp = []
    queries = []
    q = random.randint(5, 20)
    for _ in range(n):
        tmp.append(random.randint(-100, 100))
    for _ in range(q):
        u = random.randint(0, n-1)
        v = random.randint(u, n-1)
        to = random.randint(1, 10)
        if random.randint(-100, 100) <= 50:
            queries.append([1, u, v])
        else:
            queries.append([2, u, v, to])
    f = open('input.txt', 'w')
    f.writelines(str(n)+"\n")
    f.writelines(" ".join([str(x) for x in tmp]))
    f.writelines("\n"+str(q)+"\n")
    f.writelines("\n".join([" ".join([str(y) for y in x]) for x in queries]))
    f.close()
    return (n, tmp, queries)


def RangeSumSlow():
    _, ar, qu = createInput()
    p = run(['RangeSumQuery.exe'], encoding='ascii', stdout=subprocess.PIPE)
    tmp = (p.stdout)
    ans = []
    for q in qu:
        if q[0] == 1:
            ans.append(str(sum(ar[q[1]:q[2]+1])))
        else:
            for i in range(q[1], q[2]+1):
                ar[i] += q[3]
    # print("From Code")
    if tmp.strip() == "\n".join(ans):
        print("AC")
    else:
        print("Fail")
        print(ans)



def RangeMinSlow():
    _, ar, qu = createInput()
    p = run(['SegmentTree.exe'], encoding='ascii', stdout=subprocess.PIPE)
    tmp = (p.stdout)
    ans = []
    for q in qu:
        if q[0] == 1:
            ans.append(str(min(ar[q[1]:q[2]+1])))
        else:
            for i in range(q[1], q[2]+1):
                ar[i] += q[3]
    # print("From Code")
    if tmp.strip() == "\n".join(ans):
        print("AC")
    else:
        print("Fail")


def RangeMaxSlow():
    _, ar, qu = createInput()
    p = run(['SegmentTree.exe'], encoding='ascii', stdout=subprocess.PIPE)
    tmp = (p.stdout)
    ans = []
    for q in qu:
        if q[0] == 1:
            ans.append(str(max(ar[q[1]:q[2]+1])))
        else:
            for i in range(q[1], q[2]+1):
                ar[i] += q[3]
    # print("From Code")
    if tmp.strip() == "\n".join(ans):
        print("AC")
    else:
        print("Fail")
        print(ans)


def RangeMaxCountSlow():
    _, ar, qu = createInput()
    # inp = open('input.txt', 'r')
    # n = int(inp.readline().strip())
    # ar = inp.readline().strip().split(' ')
    # ar = [int(i) for i in ar]
    # q = int(inp.readline().strip())
    # qu = []
    # for i in range(q):
    #     z = inp.readline().strip().split(' ')
    #     qu.append([int(x) for x in z])

    # print(qu)
    p = run(['MaximumCountSegmentTree.exe'],
            encoding='ascii', stdout=subprocess.PIPE)
    tmp = (p.stdout)
    ans = []
    for q in qu:
        if q[0] == 1:
            c = 0
            z = max(ar[q[1]:q[2]+1])
            for i in range(q[1], q[2]+1):
                if z == ar[i]:
                    c += 1
            ans.append(str(z) + " " + str(c))
        else:
            for i in range(q[1], q[2]+1):
                ar[i] += q[3]
    # print("From Code")
    if tmp.strip() == "\n".join(ans):
        print("AC")
    else:
        print("Fail")
        print(ans)


def RangeReverseSlow():
    pass


# for i in range(200):
    # RangeMinSlow()

# for i in range(200):
    # RangeMaxSlow()

# for i in range(200):
    # RangeMaxCountSlow()

for i in range(200):
    RangeSumSlow()

# p = run(['SegmentTree.exe'], encoding='ascii')
# print(p.stdout)
