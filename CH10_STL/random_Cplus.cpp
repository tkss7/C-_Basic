#include <iostream>
#include <random>

using namespace std;

int main() 
{
    // 시드값을 얻기 위한 random_device 생성.(운영체제 단에서 제공)
    random_device rd;

    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    mt19937 gen(rd());  //C++ 난수 라이브러리(메르센 트위스터 알고리즘)

    // 0 부터 10 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    uniform_int_distribution<int> dist(0, 10);

    for (int i = 0; i < 10; i++) 
        cout << dist(gen) << ", ";  //균등분호에 난수엔진 전달(난수발생)
    cout << endl;
}