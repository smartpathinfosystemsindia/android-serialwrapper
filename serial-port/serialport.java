public class serialport {
  public static long SerialPortOpen(String jarg1) {
    long cPtr = serialportJNI.SerialPortOpen(jarg1);
    return cPtr;
  }
}
