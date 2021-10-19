#include <iostream>
#include <bitset>

using namespace std;

void print( int sa)
{
    cout<<"***"<<sa<<"***"<<endl;
    unsigned int ua = (unsigned int)sa;
    int sua = (int)ua;
    cout<<"bit sa:      "<<bitset<32>(sa)<<endl;
    cout<<"bit sa/2:    "<<bitset<32>(sa/2)<<endl;
    cout<<"bit sa>>1:   "<<bitset<32>(sa >> 1)<<endl;
    cout<<"bit ua:      "<<bitset<32>(ua)<<endl;
    cout<<"bit ua/2:    "<<bitset<32>(ua/2)<<endl;
    cout<<"bit ua>>1:   "<<bitset<32>(ua >> 1)<<endl;
    cout<<"bit usa:     "<<bitset<32>(sua)<<endl;
}

void fetch_in_int( int sa, unsigned int& lower_2_bits, unsigned int& mid_10_bits )
{
    unsigned int ua = (unsigned int)sa;
    lower_2_bits = ( ua % (1<<2) );
    mid_10_bits = ( (ua>>2) % (1<<10) );
}

void store_lower_2_bits_in_int( int& sa, unsigned int value )
{
    cout<<"**************************"<<endl;
    cout<<"store_lower_2_bits:"<<value<<endl;
    cout<<"storage before:  "<<bitset<32>(sa)<<endl;
    
    unsigned int lower_2_bits_before = 0;
    unsigned int mid_10_bits_before = 0;
    fetch_in_int( sa, lower_2_bits_before, mid_10_bits_before );
    
    // store
    unsigned int ua = (unsigned int)sa;
    ua = (((ua>>2)<<2) + value);
    sa = (int)ua;
    // store
    
    unsigned int lower_2_bits_after = 0;
    unsigned int mid_10_bits_after = 0;
    fetch_in_int( sa, lower_2_bits_after, mid_10_bits_after );
    
    cout<<"lower before:    "<<lower_2_bits_before<<endl;
    cout<<"lower after:     "<<lower_2_bits_after<<endl;
    cout<<"higher before:   "<<mid_10_bits_before<<endl;
    cout<<"higher after:    "<<mid_10_bits_after<<endl;
    cout<<"storage after:   "<<bitset<32>(sa)<<endl;
}

void store_mid_10_bits_in_int( int& sa, unsigned int value )
{
    cout<<"**************************"<<endl;
    cout<<"store_higher_10_bits:"<<value<<endl;
    cout<<"storage before:  "<<bitset<32>(sa)<<endl;
    
    unsigned int lower_2_bits_before = 0;
    unsigned int mid_10_bits_before = 0;
    fetch_in_int( sa, lower_2_bits_before, mid_10_bits_before );
    
    // store
    unsigned int ua = (unsigned int)sa;
    ua = (ua%(1<<2)) + (value<<2);
    sa = (int)ua;
    // store
    
    unsigned int lower_2_bits_after = 0;
    unsigned int mid_10_bits_after = 0;
    fetch_in_int( sa, lower_2_bits_after, mid_10_bits_after );
    
    cout<<"lower before:    "<<lower_2_bits_before<<endl;
    cout<<"lower after:     "<<lower_2_bits_after<<endl;
    cout<<"higher before:   "<<mid_10_bits_before<<endl;
    cout<<"higher after:    "<<mid_10_bits_after<<endl;
    cout<<"storage after:   "<<bitset<32>(sa)<<endl;
}

// store bits in int
void store_and_fetch_unsigned_vs_signed( unsigned int lower_2_bits, unsigned int mid_10_bits )
{
    cout<<"**************************"<<endl;
    
    int storage = 0;
    
    store_lower_2_bits_in_int( storage, lower_2_bits );
    store_mid_10_bits_in_int( storage, mid_10_bits );
}

int main()
{
    // print(1);
    // print(-1);
    
    // unsigned int lower_2_bits = 2;
    // unsinged int mid_10_bits = 57;
    
    // store_and_fetch_unsigned_vs_signed( 3, 57 );
    // store_and_fetch_unsigned_vs_signed( 1, 500 );
    
    int storage = 0;
    store_lower_2_bits_in_int( storage, 3 );
    store_mid_10_bits_in_int( storage, 57 );
    store_mid_10_bits_in_int( storage, 500 );
    store_lower_2_bits_in_int( storage, 1 );
    
    return 0;
}
