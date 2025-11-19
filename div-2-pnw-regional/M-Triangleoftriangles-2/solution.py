import sys
import io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, newline='\n', encoding='utf-8')

def try_all_angles(t1, t2, t3):
    favs = [sorted(t2), sorted(t3)]

    for i in range(3):
        a = t1[i]
        b = t1[(i+1) % 3]
        c = t1[(i+2) % 3]
        
        for split1 in range(5, a, 5):
            split2 = a - split1

            cut_angle1 = 180 - split1 - b
            cut_angle2 = 180 - split2 - c
            
            if cut_angle1 % 5 != 0 or cut_angle2 % 5 != 0:
                continue
            
            tri1 = sorted([split1, b, cut_angle1])
            tri2 = sorted([split2, c, cut_angle2])
            
            for opt1 in favs:
                for opt2 in favs:
                    if (tri1 == opt1 and tri2 == opt2) or (tri1 == opt2 and tri2 == opt1):
                        return True
    
    return False


def single_test():
    t1 = tuple(map(int, input().split()))
    t2 = tuple(map(int, input().split()))
    t3 = tuple(map(int, input().split()))

    return 'YES' if try_all_angles(t1, t2, t3) else 'NO'


def main():
    n = int(input())
    
    for _ in range(n):
        print(single_test())


if __name__ == "__main__":
    main()
