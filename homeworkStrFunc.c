
size_t strlen1(char* s){
    size_t i = 0;
    while (s[i]){
        i++;
    }
    return i;
}

void strcpy(char* dst, char* src){
    int i = 0;
    while (src[i]){
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
}

void strcat(char* dst, char* src){
    int i = 0;
    int j = 0;
    while (dst[i]){
        i++;
    }
    while (src[j]){
        dst[i+j] = src[j];
        j++;
    }
        dst[i+j] = 0;
}

int strcmp(char* s1, char* s2){
    int i = 0;
    int res = 0;
    while (s1[i] || s2[i]){
        if (s1[i] == s2[i]){
            i++;
        }
        else{
            res = (int)s1[i] - (int)s2[i];
            break;
        }
    }
    return res;
}

