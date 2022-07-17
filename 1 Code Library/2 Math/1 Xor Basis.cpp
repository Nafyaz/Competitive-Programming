// basis[i] keeps the mask of the vector whose f value is i
int basis[d];

// Current size of the basis
int sz;

void insertVector(int mask) 
{
	for (int i = 0; i < d; i++) 
    {
        // continue if i != f(mask)
		if ((mask & 1 << i) == 0) 
            continue; 

        // If there is no basis vector with the i'th bit set, then insert this vector into the basis
		if (!basis[i]) 
        { 
			basis[i] = mask;
			++sz;
			
			return;
		}

        // Otherwise subtract the basis vector from this vector
		mask ^= basis[i]; 
	}
}
