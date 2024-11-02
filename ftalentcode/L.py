import heapq
import math

class Part:
    def __init__(self, index, deviation):
        self.index = index
        self.deviation = deviation

    def __lt__(self, other):
        return self.deviation < other.deviation

def main():
    n, k = map(float, input().split())
    n = int(n)
    a = list(map(int, input().split()))
    s = list(map(int, input().split()))

    pq = []
    total_deviation = 0.0
    for i in range(n):
        deviation = abs(a[i] - s[i]) / s[i]
        total_deviation += deviation
        heapq.heappush(pq, Part(i, deviation))

    time = 0
    while total_deviation > k:
        part = heapq.heappop(pq)
        i = part.index
        current_deviation = part.deviation

        if a[i] > s[i]:
            a[i] -= 1
        else:
            a[i] += 1

        new_deviation = abs(a[i] - s[i]) / s[i]
        total_deviation = total_deviation - current_deviation + new_deviation
        heapq.heappush(pq, Part(i, new_deviation))
        time += 1

    print(time)

if __name__ == "__main__":
    main()
