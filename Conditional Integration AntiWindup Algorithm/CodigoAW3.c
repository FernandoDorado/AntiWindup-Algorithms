/* CÓDIGO DEL CONTROLADOR */
/* Las variables utilizadas deben haber sido DECLARADAS PREVIAMENTE en "Declaraciom_de_variables.c" */ 

 /* La medida salida del sistema ya está declarada como Yk */
 /* La señal de control ya está declarado como Ureal */
 /* Hay disponible una salida auxiliar ya declarada como POutAux */
 /* El tiempo de muestreo ya está declarado como Tm */

  tiempo = ssGetT(S);  /* Tiempo de la simulación */
 
   /* Incluir código para calcular Ureal */ 
  
  /*Modifico referencia*/
  if (tiempo < 100.) Rk=70.;
  else if(tiempo<250.) Rk=100.;
  else if(tiempo<350.) Rk=500.;
  else Rk=70;
  
  /*Calculo de la señal de la salida real*/
  
  if(tiempo<100.)
    Ureal=Ueq;
  else /*Activo señal de control*/
  {
  /*Cálculo error actual*/
  ek=Rk-Yk;
  /*Integracion*/
  Integ+=Tm*ek;
  
  ypk=Yk+Td*(Yk-yk1)/Tm;
  uk=Kp*Rk+Kp/Ti*Integ-Kp*ypk;  


  ymax=Rk+(1/Ti*Integ-Umin/Kp);
  ymin=Rk+(1/Ti*Integ-Umax/Kp);
  
 /*Saturacion de la señal de control*/
   
 if(Ureal>Umax) Ureal=Umax;
 if(Ureal<Umax) Ureal=Umin;
 if(ypk<ymin || ypk>ymax) Integ-=Tm*ek;
   Ureal=Ueq+uk;
  /*Actualizamos errores y actuaciones*/
   ek1=ek;
   yk1=Yk;
    
  /*CONTROL NORMAL*/
 /*Calculo incremento señal de control*/
 /* uk=(b0*ek+b1*ek1+b2*ek2-a1*uk1-a2*ek2)/a0;
 /*Actualizacion variables*/
 /* uk2=uk1;
 /* uk1=uk;
 /*ek2=ek1;
 /* ek1=ek;*/
  }
 
  POutAux=Rk;
  
  /* NO ES NECESARIO INCLUIR return */
  /* BASTA CON DEJAR EN LA VARIABLE Ureal EL VALOR FINAL DE SALIDA */
  /* BASTA CON DEJAR EN LA VARIABLE Ureal EL VALOR FINAL DE SALIDA */