def solution(n, lost, reserve):
    answer = 0
    student = []
    for i in range(0, n + 2):
        student.append(1)
    student[0] = student[n + 1] = 0
    for l in lost:
        student[l] -= 1
    for r in reserve:
        student[r] += 1
    for i in range(1, n + 1):
        if student[i] == 0:
            if student[i - 1] > 1: #앞 사람이 체육복을 가지고 있는 경우
                student[i - 1] -= 1
                student[i] += 1
            elif student[i + 1] > 1:
                student[i + 1] -= 1
                student[i] += 1
    answer = sum(1 for i in student if i > 0)
    return answer
