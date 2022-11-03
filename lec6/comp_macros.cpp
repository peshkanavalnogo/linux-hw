#define USE_GPU
#define USE_FLOAT

#if defined(USE_GPU) && defined(USE_FLOAT)
int main(){
    return 1;
}
#elif defined(USE_GPU) && !defined(USE_FLOAT)
int main(){
    return 2;
}
#elif !defined(USE_GPU) && defined(USE_FLOAT)
int main(){
    return 3;
{
#else
int main(){
    return 4;
}
#endif
