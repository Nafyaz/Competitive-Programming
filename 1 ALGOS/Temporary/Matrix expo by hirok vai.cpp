#include<bits/stdc++.h>
using namespace std;

template<int N> class Matrix
{
public:
    long long  arr[N][N];

    Matrix()
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                arr[i][j] = 0;
        }
    }

    Matrix<N> operator *(const Matrix<N> &in)
    {
        Matrix<N> ret ;
        for( int i = 0 ; i < N ; i++ )
        {
            for( int j = 0 ; j < N ; j++ )
            {
                for( int k = 0 ; k < N ; k++ )
                    ret.arr[i][j] += (arr[i][k] ) * ( in.arr[k][j] );
            }
        }
        return ret ;
    }

    Matrix<N> operator ^( int p )
    {

        Matrix<N> ret ;
        for( int i = 0 ; i < N ; i++ )
            ret.arr[i][i] = 1;

        Matrix<N> ME = *this ;

        while( p )
        {
            if( p&1 )
                ret = ret * ME ;

            ME = ME * ME ;
            p >>= 1 ;
        }
        return ret ;
    }
};

int main()
{
    Matrix<2, 3> m;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
            cout << m.arr[i][j] << " ";
        cout << endl;
    }
}

