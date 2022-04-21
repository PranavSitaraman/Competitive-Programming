import copy
import json

def tower():
    field = data["airspace"]
    newfield = copy.deepcopy(field)
    for i in range(len(newfield)):
        for j in range(len(newfield[i])):
            newfield[i][j] = 1 - field[i][j]
    field = copy.deepcopy(newfield)
    for i in range(len(newfield)):
        for j in range(len(newfield[i])):
            if newfield[i][j] == 1:
                count = 0
                try:
                    count += newfield[i - 1][j]
                except:
                    pass
                try:
                    count += newfield[i + 1][j]
                except:
                    pass
                try:
                    count += newfield[i][j + 1]
                except:
                    pass
                try:
                    count += newfield[i][j - 1]
                except:
                    pass
                if count <= 1:
                    newfield[i][j] = 0
    for i in range(len(newfield)):
        for j in range(1, len(newfield[i]) - 1):
            if (
                newfield[i][j - 1] == 0
                and newfield[i][j] == 1
                and newfield[i][j + 1] == 1
            ):
                newfield[i][j] = 0
            if (
                newfield[i][j - 1] == 1
                and newfield[i][j] == 1
                and newfield[i][j + 1] == 0
            ):
                newfield[i][j] = 0
    for i in range(len(newfield)):
        for j in range(len(newfield[i])):
            if newfield[i][j] == 1:
                count = 0
                try:
                    count += newfield[i - 1][j]
                except:
                    pass
                try:
                    count += newfield[i + 1][j]
                except:
                    pass
                try:
                    count += newfield[i][j + 1]
                except:
                    pass
                try:
                    count += newfield[i][j - 1]
                except:
                    pass
                try:
                    count += newfield[i - 1][j - 1]
                except:
                    pass
                try:
                    count += newfield[i - 1][j + 1]
                except:
                    pass
                try:
                    count += newfield[i + 1][j - 1]
                except:
                    pass
                try:
                    count += newfield[i + 1][j + 1]
                except:
                    pass
                if count == 0:
                    newfield[i][j] = 0
    for i in range(len(newfield)):
        vals = []
        total = 0
        for j in range(len(newfield[i])):
            if newfield[i][j] == 1:
                vals.append(j)
                total += j
        if len(vals) == 0:
            continue
        result = round(total / len(vals))
        for a in vals:
            newfield[i][a] = 0
        newfield[i][result] = 1
    for q in range(8, -1, -1):
        for i in range(len(newfield)):
            for j in range(len(newfield[i])):
                if newfield[i][j] == 1:
                    count = 0
                    try:
                        count += newfield[i - 1][j]
                    except:
                        pass
                    try:
                        count += newfield[i + 1][j]
                    except:
                        pass
                    try:
                        count += newfield[i][j + 1]
                    except:
                        pass
                    try:
                        count += newfield[i][j - 1]
                    except:
                        pass
                    try:
                        count += newfield[i - 1][j - 1]
                    except:
                        pass
                    try:
                        count += newfield[i - 1][j + 1]
                    except:
                        pass
                    try:
                        count += newfield[i + 1][j - 1]
                    except:
                        pass
                    try:
                        count += newfield[i + 1][j + 1]
                    except:
                        pass
                    if count == q:
                        try:
                            newfield[i - 1][j] = 0
                        except:
                            pass
                        try:
                            newfield[i + 1][j] = 0
                        except:
                            pass
                        try:
                            newfield[i][j + 1] = 0
                        except:
                            pass
                        try:
                            newfield[i][j - 1] = 0
                        except:
                            pass
                        try:
                            newfield[i - 1][j - 1] = 0
                        except:
                            pass
                        try:
                            newfield[i - 1][j + 1] = 0
                        except:
                            pass
                        try:
                            newfield[i + 1][j - 1] = 0
                        except:
                            pass
                        try:
                            newfield[i + 1][j + 1] = 0
                        except:
                            pass
    points = []
    for i in range(len(newfield) - 1, -1, -1):
        a = -1
        for j in range(len(newfield[i])):
            if newfield[i][j] == 1:
                a = j
                break
        if a != -1:
            points.append([i, a])
    out = []
    prevslope = 0
    for i in range(len(points)):
        slope = 0.0
        if i == 0:
            out.append(points[0])
        elif i == 1:
            changex = points[i][0] - out[-1][0]
            changey = points[i][1] - out[-1][1]
            if changey == 0:
                prevslope = 25.0
            else:
                prevslope = float(changex) / changey
        else:
            changex = points[i][0] - out[-1][0]
            changey = points[i][1] - out[-1][1]
            if changey == 0:
                slope = 25.0
            else:
                slope = float(changex) / changey
            if (slope < 0.5 * prevslope or slope > 2 * prevslope) and (
                not (
                    (abs(prevslope) > 10 and abs(slope) > 10)
                    or (abs(prevslope) < 0.1 and abs(slope) < 0.1)
                )
            ):
                out.append(points[i - 1])
                changex = points[i][0] - out[-1][0]
                changey = points[i][1] - out[-1][1]
                if changey == 0:
                    prevslope = 25.0
                else:
                    prevslope = float(changex) / changey
                i += 1
            elif (
                points[i][1] - points[i - 1][1] > 40
                and (slope < 0.8 * prevslope or slope > 1.2 * prevslope)
                and (
                    not (
                        (abs(prevslope) > 10 and abs(slope) > 10)
                        or (abs(prevslope) < 0.1 and abs(slope) < 0.1)
                    )
                )
            ):
                out.append(points[i - 1])
                changex = points[i][0] - out[-1][0]
                changey = points[i][1] - out[-1][1]
                if changey == 0:
                    prevslope = 25.0
                else:
                    prevslope = float(changex) / changey
    i = 0
    while True:
        if i >= len(out):
            break
        if i != 0:
            if (
                abs(out[i][0] - out[i - 1][0]) < 20
                and abs(out[i][1] - out[i - 1][1]) < 20
            ):
                out[i - 1][0] = round((out[i][0] + out[i - 1][0]) / 2.0)
                out[i - 1][1] = round((out[i][1] + out[i - 1][1]) / 2.0)
                out.pop(i)
                i -= 1
        i += 1
    bits = []
    out[0][0] = len(newfield) - 1
    for i in range(min(len(out), 4)):
        bits.extend([int(j) for j in format(out[i][0], "08b")])
        bits.extend([int(j) for j in format(out[i][1], "08b")])
    while len(bits) < 64:
        bits.append(0)
    print(json.dumps({"bits": bits}))
    return {"bits": bits}


def drone():
    bits = data["bits"]
    points = []
    for i in range(4):
        num = 0
        nums = []
        for j in range(8):
            num += bits[16 * i + j] * pow(2, 7 - j)
        nums.append(num)
        num = 0
        for j in range(8):
            num += bits[16 * i + 8 + j] * pow(2, 7 - j)
        nums.append(num)
        points.append(nums)
    directions = []
    for i in range(4):
        if i == 0:
            continue
        numUp = points[i - 1][0] - points[i][0]
        numRight = points[i][1] - points[i - 1][1]
        while True:
            if numRight == 0:
                directions.extend(numUp * ["U"])
                break
            if numUp == 0:
                if numRight < 0:
                    directions.extend(abs(numRight) * ["L"])
                else:
                    directions += numRight * "R"
                break
            if numRight > 0:
                if numUp >= numRight:
                    directions.extend(int(numUp / numRight) * ["U"] + ["R"])
                    numUp -= int(numUp / numRight)
                    numRight -= 1
                else:
                    directions.extend(int(numRight / numUp) * ["R"] + ["U"])
                    numRight -= int(numRight / numUp)
                    numUp -= 1
            else:
                if numUp >= abs(numRight):
                    directions.extend(int(numUp / abs(numRight)) * ["U"] + ["L"])
                    numUp -= int(numUp / abs(numRight))
                    numRight += 1
                else:
                    directions.extend(int(abs(numRight) / numUp) * ["L"] + ["U"])
                    numRight += int(abs(numRight) / numUp)
                    numUp -= 1
    print(json.dumps({"col": points[0][1], "moves": directions}))
    return {"col": points[0][1], "moves": directions}

#field = []
#task = "path"
#with open("CMIMC/2022/" + task + ".txt") as f:
#    for line in f:
#        row = []
#        for a in line:
#            if a == "0":
#                row.append(0)
#            elif a == "1":
#                row.append(1)
#        field.append(row)
#data = {
#    "role": "tower",
#    "generator": task,
#    "parameter": 10,
#    "airspace":
#    field
#}
#p = tower()
#data = {
#    "role": "drone",
#    "generator": task,
#    "parameter": 10,
#    "airspace": field,
#    "bits": p["bits"],
#}
#q = drone()

data = json.loads(input())
if (data["role"] == "tower"):
    tower()
else:
    drone()