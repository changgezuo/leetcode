class Solution{
public:
	//math problem just analyze the odd the even of p and q
	int mirrorReflection(int p, int q){
            while(p % 2 == 0 && q % 2 == 0){
                p /= 2;
		q /= 2;
	    }
	    if(p & 1 && q & 1)return 1;
	    if(p & 1)return 0;
	    return 2;

	}


};
