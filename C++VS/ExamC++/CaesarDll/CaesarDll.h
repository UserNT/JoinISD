#ifndef CAESARDLL_H_
#define CAESARDLL_H_

#endif

typedef unsigned int uint;

__declspec(dllexport) char* encrypt(const char* message, uint key);
__declspec(dllexport) char* decrypt(const char* message, uint key);

