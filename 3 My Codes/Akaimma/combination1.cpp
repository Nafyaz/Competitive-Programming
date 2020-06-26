//Matrix expo Rafid

struct Mat {
	// Mat row and col max size
	#define sz 107
	#define mod 1000000007
	// notice the mod here

	int row, col;
	int v[sz][sz];

	Mat(int r=0, int c=0) {
		row = r, col = c;
		memset(v, 0, sizeof v);
	}

	Mat operator * (const Mat &p) const {
		assert(col == p.row);

		Mat ret(row, p.col);
		ll mod2 = (ll) mod * mod;
		for(int i=0; i<ret.row; ++i) {
			for(int j=0; j<ret.col; ++j) {
				long long sum = 0;
				for(int k=0; k<col; ++k) {
					sum += (1LL * v[i][k] * p.v[k][j]);
					if(sum >= mod2) sum -= mod2;
				}
				ret.v[i][j] = sum % mod;
			}
		}

		return ret;
	}

	Mat power (int p) {
		assert(row == col);

		Mat base = *this;
		Mat ret(row, col);
		for(int i=0; i<row; ++i) ret.v[i][i] = 1;

		while(p > 0) {
			if(p & 1) ret = ret * base;
			base = base * base;
			p >>= 1;
		}

		return ret;
	}
};

// inverses a matrix, make sure data is double type
Mat inverse(const Mat &p) {
    // assert(p.row == p.col);

    int n = p.row;
    Mat temp(n, n+n);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            temp.v[i][j] = p.v[i][j];
        }
        temp.v[i][n+i] = 1;
    }

    for(int i=0; i<n; ++i) {
        int tr = i;
        for(int j=i+1; j<n; ++j) {
            if(fabs(temp.v[j][i]) > fabs(temp.v[tr][i])) tr = j;
        }
        for(int j=0; j<n+n; ++j) swap(temp.v[i][j], temp.v[tr][j]);

		double val = temp.v[i][i];
        for(int j=0; j<n+n; ++j) temp.v[i][j] /= val;

        // assert(abs(temp.v[i][i]) > 0);
		// or simply return false

        for(int j=0; j<n; ++j) {
            if(j == i) continue;
            for(int k=n+n-1; k>=i; --k) {
                temp.v[j][k] -= temp.v[i][k] * temp.v[j][i] / temp.v[i][i]; // be careful here
            }
        }
    }

    Mat ret(n, n);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            ret.v[i][j] = temp.v[i][n+j];
        }
    }
    return ret;
}
