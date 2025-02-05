#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("\nElements are\n");

    for(int i=0; i<arr.length; i++)
        printf("%d ",arr.A[i]);
    printf("\n");
}
void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    if(index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;        
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    if(index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (int i = index; i < arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x; 
    }
    return 0;
}

int LinearSearch(struct Array arr, int key)
{
    for(int i=0; i<arr.length; i++)
        if(key == arr.A[i])
            return i;
    return -1;
}
/* improve methods */
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/* 1. transportion */
int Improve_LinearSearch_1(struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    return -1;
}
/* 2. move to head/front */
int Improve_LinearSearch_2(struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    return -1;
}


int BinarySearch(struct Array arr, int key)
{
    int l,h,mid;
    l = 0;
    h = arr.length - 1;

    while (l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinSearch(int a[],int l, int h, int key)
{
    int mid;
    if(l<=h)
    {
        mid = (l+h)/2;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return RBinSearch(a,l,mid-1,key);
        else
            return RBinSearch(a,mid+1,h,key);
    }

    return -1;
}

int Get(struct Array arr, int index)
{
    if(index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}
void Set(struct Array *arr, int index, int x)
{
    if(index >= 0 && index < arr->length)
        arr->A[index] = x;
}
int Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++)
        if(max < arr.A[i])
            max = arr.A[i];
    return max;
}
int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=1; i<arr.length; i++)
        if(min > arr.A[i])
            min = arr.A[i];
    return min;
}

int Sum(struct Array arr)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
        total += arr.A[i];
    return total;
}
float Avg(struct Array arr)
{
    return (float) Sum(arr)/arr.length;
}

void Reverse(struct Array *arr)
{
    int *B;
    int i,j;
    B = (int*) malloc(arr->length * sizeof(int));

    for(i=0,j=arr->length-1; j>=0; i++,j--)
        B[i] = arr->A[j]; 
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];

    free(B);
}

void Reverse_Swap(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1; i<j; i++,j--)
        swap(&arr->A[i], &arr->A[j]);

}

void Shift_left(struct Array *arr)
{
    int x = arr->A[0];
    for (int i = 1; i < arr->length; i++)
        arr->A[i-1] = arr->A[i];
    arr->A[arr->length-1] = 0;    
}
void Rotate_left(struct Array *arr)
{
        int x = arr->A[0];
    for (int i = 1; i < arr->length; i++)
        arr->A[i-1] = arr->A[i];
    arr->A[arr->length-1] = x; 
}


void InsertSort(struct Array *arr, int x)
{
    int i = arr->length -1;
    if(arr->length == arr->size)
        return;
    
    while (i>=0 && arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}
int isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length-1; i++)
        if(arr.A[i] > arr.A[i+1])
            return 0; 
    
    return 1;
}

void Rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length-1;
    while (i<j)
    {
        while(arr->A[i] < 0)i++;
        while(arr->A[j] >= 0)j--;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }
}

struct Array* Marge(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array*) malloc(sizeof(struct Array));
    
    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for(;i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for(;j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}

struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array*) malloc(sizeof(struct Array));
    
    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else if(arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for(;i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for(;j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array*) malloc(sizeof(struct Array));
    
    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            i++;
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else if(arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array*) malloc(sizeof(struct Array));
    
    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else if(arr1->A[i] == arr2->A[j])
        {
            i++;
            j++;
        }
    }
    for(;i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main()
{
    struct Array arr1;
    int ch;
    int x,index;

    printf("Enter size of an array ");
    scanf("%d",&arr1.size);
    arr1.A = (int*) malloc(arr1.size*sizeof(int));
    do{
        printf("\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            /* 1. Insert */
            printf("Enter an element and index ");
            scanf("%d%d",&x,&index);
            Insert(&arr1,index,x);
            break;
        case 2:
            /* 2. Delete */
            printf("Enter index ");
            scanf("%d",&index);
            x = Delete(&arr1,index);
            printf("Deleted element is %d\n",x);
            break;
        case 3:
            /* 3. Search */
            printf("Enter element to search ");
            scanf("%d",&x);
            index = LinearSearch(arr1,x);
            printf("Element index %d\n",index);
            break;
        case 4:
            /* 4. Sum */
            printf("Sum is %d\n",Sum(arr1));
            break;
        case 5:
            /* 5. Display */
            Display(arr1);
            break;
        }
    }while(ch<6);
    
    printf("Good Bye :D\n");
    return 0;
}

