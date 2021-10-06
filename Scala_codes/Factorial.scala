import scala.io.StdIn.readInt
object Main{
  def main(args:Array[String]): Unit ={
    val t=readInt()
    var f = 1
    for(i<-1 until t+1){
        f = f*i
      }
      println("Factorial of "+t+"="+f)
    }
}
