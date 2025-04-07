# 一条导入语，用于从power.py文件导入power函数
from power import power

def test_power():
    assert power(2, 3) == 8
    assert power(5, 0) == 1
    assert power(0, 0) == 1
    
    print("Past all the test")
    
# 用于判断当前模块是否是主程序。如果是主程序，运行函数；
# 如果该文件是被其他模块导入的，则下面函数不会被执行。
if __name__ == "__main__":
    test_power()
    