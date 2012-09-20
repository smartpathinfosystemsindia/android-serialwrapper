#include <jni.h>
#include <stdlib.h>
#include <jni_md.h>

#if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#define JAVAEXPORT __attribute__ ((visibility("default")))
#else
#define JAVAEXPORT
#endif


#include "sp_serial.h"


#ifdef __cplusplus
extern "C"
{
#endif

    JAVAEXPORT jlong JNICALL Java_serialportJNI_SerialPortOpen (JNIEnv * jenv,
								jclass jcls,
								jstring jarg1)
    {
	jlong jresult = 0;
	void *result = 0;

	  (void) jenv;
	  (void) jcls;
	char *arg1 = (char *) 0;
	  printf ("entering the jni\n");
	if (jarg1)
	  {
	      arg1 = (char *) (*jenv)->GetStringUTFChars (jenv, jarg1, 0);
	      if (!arg1)
		  return 0;
	  }
	printf ("opening the device\n");
	result = (void *) sp_serial_open (arg1);
	*(void **) &jresult = result;
	return jresult;
    }


#ifdef GG


    JAVAEXPORT jint JNICALL Java_serialportJNI_sp_serial_1Close (JNIEnv *
								 jenv,
								 jclass jcls,
								 jlong jarg1)
    {
	jint jresult = 0;
	void *arg1 = (void *) 0;
	int result;

	(void) jenv;
	(void) jcls;
	arg1 = *(void **) &jarg1;
	result = (int) sp_serial_Close (arg1);
	jresult = (jint) result;
	return jresult;
    }


    JAVAEXPORT jlong JNICALL Java_serialportJNI_sp_serial_1Get_1Width (JNIEnv
								       * jenv,
								       jclass
								       jcls,
								       jlong
								       jarg1)
    {
	jlong jresult = 0;
	void *arg1 = (void *) 0;
	unsigned int result;

	(void) jenv;
	(void) jcls;
	arg1 = *(void **) &jarg1;
	result = (unsigned int) sp_serial_Get_Width (arg1);
	jresult = (jlong) result;
	return jresult;
    }


    JAVAEXPORT jlong JNICALL Java_serialportJNI_sp_serial_1Get_1Height (JNIEnv
									*
									jenv,
									jclass
									jcls,
									jlong
									jarg1)
    {
	jlong jresult = 0;
	void *arg1 = (void *) 0;
	unsigned int result;

	(void) jenv;
	(void) jcls;
	arg1 = *(void **) &jarg1;
	result = (unsigned int) sp_serial_Get_Height (arg1);
	jresult = (jlong) result;
	return jresult;
    }


    JAVAEXPORT jint JNICALL Java_serialportJNI_sp_serial_1Get_1Data (JNIEnv *
								     jenv,
								     jclass
								     jcls,
								     jlong
								     jarg1,
								     jstring
								     jarg2,
								     jlong
								     jarg3)
    {
	jint jresult = 0;
	void *arg1 = (void *) 0;
	char *arg2 = (char *) 0;
	unsigned int arg3;
	int result;

	(void) jenv;
	(void) jcls;
	arg1 = *(void **) &jarg1;
	arg2 = 0;
	if (jarg2)
	  {
	      arg2 = (char *) (*jenv)->GetStringUTFChars (jenv, jarg2, 0);
	      if (!arg2)
		  return 0;
	  }
	arg3 = (unsigned int) jarg3;
	result = (int) sp_serial_Get_Data (arg1, arg2, arg3);
	jresult = (jint) result;
	if (arg2)
	    (*jenv)->ReleaseStringUTFChars (jenv, jarg2, (const char *) arg2);
	return jresult;
    }




    JAVAEXPORT jint JNICALL Java_serialportJNI_sp_serial_1Is_1Busy (JNIEnv *
								    jenv,
								    jclass
								    jcls,
								    jlong
								    jarg1)
    {
	jint jresult = 0;
	void *arg1 = (void *) 0;
	int result;

	(void) jenv;
	(void) jcls;
	arg1 = *(void **) &jarg1;
	result = (int) sp_serial_Is_Busy (arg1);
	jresult = (jint) result;
	return jresult;
    }


    JAVAEXPORT jint JNICALL Java_serialportJNI_sp_serial_1Init_1Read (JNIEnv *
								      jenv,
								      jclass
								      jcls,
								      jlong
								      jarg1)
    {
	jint jresult = 0;
	void *arg1 = (void *) 0;
	int result;

	(void) jenv;
	(void) jcls;
	arg1 = *(void **) &jarg1;
	result = (int) sp_serial_Init_Read (arg1);
	jresult = (jint) result;
	return jresult;
    }




    JNIEXPORT void JNICALL Java_serialportJNI_fillByteArray (JNIEnv * env,
							     jbyteArray array,
							     jlong length)
    {
	jboolean isCopy;
	jsize i;
	jbyte *buffer = (*env)->GetByteArrayElements (env, array, &isCopy);
	// jsize length = (*env)->GetArrayLength(env, array);
	printf ("length=%d\n", length);

	// do something with the buffer here, replace with something meaningful
	// PAY ATTENTION TO BUFFER OVERFLOW, DO NOT WRITE BEYOND BUFFER LENGTH
	for (i = 0; i < length; ++i)
	    buffer[i] = i;

	// here it is important to use 0 so that JNI takes care of copying
	// the data back to the Java side in case GetByteArrayElements returned a copy
	(*env)->ReleaseByteArrayElements (env, array, buffer, 0);
    }




    JAVAEXPORT jshort JNICALL Java_serialportJNI_sp_serial_1Get_1Byte (JNIEnv
								       * jenv,
								       jclass
								       jcls,
								       jlong
								       jarg1,
								       jlong
								       jarg2)
    {
	jshort jresult = 0;
	void *arg1 = (void *) 0;
	unsigned int arg2;
	unsigned char result;

	(void) jenv;
	(void) jcls;
	arg1 = *(void **) &jarg1;
	arg2 = (unsigned int) jarg2;
	result = (unsigned char) sp_serial_Get_Byte (arg1, arg2);
	jresult = (jshort) result;
	return jresult;
    }


    JAVAEXPORT jint JNICALL Java_serialportJNI_sp_serial_1End_1Read (JNIEnv *
								     jenv,
								     jclass
								     jcls,
								     jlong
								     jarg1)
    {
	jint jresult = 0;
	void *arg1 = (void *) 0;
	int result;

	(void) jenv;
	(void) jcls;
	arg1 = *(void **) &jarg1;
	result = (int) sp_serial_End_Read (arg1);
	jresult = (jint) result;
	return jresult;
    }

#endif


#ifdef __cplusplus
}
#endif
