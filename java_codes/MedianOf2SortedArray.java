public class MedianOf2SortedArray {
    public double findMedian(int[] arr1,int[] arr2){
       
        int n=arr1.length;
        int m=arr2.length;
        if(n>m){
            return findMedian(arr2, arr1);
        }
        int lo=0;
        int hi=n;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int mid2=(n+m+1)/2 - mid;
            int xL=mid==0?Integer.MIN_VALUE:arr1[mid-1];
            int yL=mid2==0?Integer.MIN_VALUE:arr2[mid2-1];

            int xR=mid==n?Integer.MAX_VALUE:arr1[mid];
            int yR=mid2==m?Integer.MAX_VALUE:arr2[mid2];

            if(xL<=yR && yL<xR){
                if((n+m)%2==0){
                    return ((double)Math.max(xL,yL) + Math.min(xR,yR))/2; 
                }else{
                    return Math.max(xL,yL);
                }
            }else if(xL>yR){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return 0;

    }
    public static void main(String[] args) {
        int[] arr=new int[]{-10,3,8,12,17,22};
        int[] arr1=new int[]{-3,4,1,111,144,166,167,200,221};
        MedianOf2SortedArray b=new MedianOf2SortedArray();
        MajorityElement a=new MajorityElement();
        System.out.print(a.findMajor(arr));
        System.out.println(b.findMedian(arr, arr1));
    }   
}
