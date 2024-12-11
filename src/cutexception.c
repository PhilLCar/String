#include <cutexception.h>

#define TYPENAME CutException

CutException *_(Construct)(const char *message, ...)
{
  if (this) {
    va_list argptr;
    va_start(argptr, message);
    
    String *msg = String_format(message, argptr);

    va_end(argptr);

    Exception_Construct(BASE(0), "%s", msg->base);

    DELETE(msg);
  }

  return this;
}

void _(Destruct)()
{ 
  Exception_Destruct(BASE(0));
}

#undef TYPENAME