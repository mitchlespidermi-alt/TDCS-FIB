/*
 * MFI_sid.h
 *
 * Code generation for model "MFI_sf".
 *
 * Model version              : 1.0
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Wed Apr 06 14:57:21 2016
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: MFI_sf.c
 */

/* statically allocated instance data for model: MFI */
{
  extern P_MFI_T MFI_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_MFI_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_MFI_T));
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &MFI_DefaultP);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 2399568790U);
    ssSetChecksumVal(rts, 1, 2120137772U);
    ssSetChecksumVal(rts, 2, 55408795U);
    ssSetChecksumVal(rts, 3, 2199959993U);
  }
}
