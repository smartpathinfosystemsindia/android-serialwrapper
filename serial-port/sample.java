 class sample {
  static {
    System.loadLibrary("serialport");
  }
  static long device;

  public static void main(String argv[]) {
	
    System.out.println("testing");
    String str = "/dev/ttyS0";
    device = serialport.SerialPortOpen(str);
    System.out.println("opened"+device);
 }
}

