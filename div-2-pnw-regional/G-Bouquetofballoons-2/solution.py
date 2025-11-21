import sys
import io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, newline='\n', encoding='utf-8')

def main():
    n, d, m = map(int, input().split())
    times = list(map(int, input().split()))
    times.sort()
    
    total_deflation = 0
    cumsum = 0
     
    for k in range(1, n + 1):
        if k > 1:
            cumsum += times[k - 2] # cumulative sum of prev els (1 indexed so -2)
            total_deflation += cumsum # Total deflation that's occured
        
        # Remove num balloons that are fully deflated
        # d / d means fully deflated so if we track total deflation
        # then we can remove it from the current problem we're on to get
        # number of balloons still alive ;-;
        total_capacity = k - total_deflation / d 
        
        if total_capacity >= m:
            print(k)
            return
    
    print(-1)


if __name__ == "__main__":
    main()

