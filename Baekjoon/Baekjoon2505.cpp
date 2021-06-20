/*
    백준 2505번 두 번 뒤집기
*/

#include <iostream>

void reverse(int array[], int left, int right)
{
    if(left < right)
    {
        std::swap(array[left], array[right]);
        reverse(array,left+1,right-1);
    }
}

int main()
{
    int n;
    int array[10001] = {0};
    int temp[10001] = {0};
    int left = -1,right = -1;
    int ResultLeft[2];
    int ResultRight[2];
    int count = 0;
    
    std::cin >> n;
    
    for(int i=1;i<=n;i++)
    {
        std::cin >> array[i];
        temp[i] = array[i];
    }

    for(int i=1; i<=n; i++)
    {
        //위치와 다른숫자의 시작 경우
        if(array[i] != i && left == -1)
        {
            left = i;
            ResultLeft[count] = i;
            continue;
        }
        else if(array[i] == left)
        {
            // left 위치에 들어가야할 숫자를 찾아야함

            right = i;
            ResultRight[count] = i;
            count++;

            // 역순 정렬
            reverse(array, left, right);

            left = -1;
            right = -1;
            i = 1;
        }
    }

    // 두번 뒤집어서 정답을 못 찾은 경우 뒤에서부터 다시 찾는다
    if(count > 2)
    {
        count = 0;

        for(int i = n; i > 0; i--)
        {
            //위치와 다른숫자의 시작 경우
            if(temp[i] != i && right == -1)
            {
                right = i;
                ResultRight[count] = i;
                
                continue;
            }
            else if(temp[i] == right)
            {
                left = i;
                ResultLeft[count] = i;
                count++;

                reverse(temp,left,right);

                right = -1;
                i = n;
            }
        }
    }
    
    if(count == 2)
    {
        std::cout<<ResultLeft[0]<<" "<<ResultRight[0]<<"\n";
        std::cout<<ResultLeft[1]<<" "<<ResultRight[1]<<"\n";
    }
    else if(count == 1)
    {
        std::cout << ResultLeft[0] << " "<< ResultRight[0] << "\n";
        std::cout<<1<<" "<< 1 << "\n";
    }

    else if(count == 0)
    {
        std::cout<<1<<" "<<1<<"\n";
        std::cout<<1<<" "<<1<<"\n";
    }

    return 0;
}