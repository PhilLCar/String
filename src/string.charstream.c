#include <string.charstream.h>

#ifdef STRING_CHARSTREAM_H

#define TYPENAME CharStream

////////////////////////////////////////////////////////////////////////////////
String *_(GetLine)()
{
	String *line = NEW (String) ("");
	char c;

	while((c = CharStream_Get(this)) != '\n' && !BASE(0)->eos) {
    if (c != '\r') String_Append(line, c); 
  } 

	if (BASE(0)->eos && !line->length) {
		DELETE (line);
	}

  return line;
}

////////////////////////////////////////////////////////////////////////////////
String *_(ReadLine)()
{
	String *line = NEW (String) ("");
	char c;

	while((c = CharStream_Read(this)) != '\n' && !BASE(0)->eos) {
    if (c != '\r') String_Append(line, c); 
  } 

	if (BASE(0)->eos && !line->length) {
		DELETE (line);
	}

  return line;
}

////////////////////////////////////////////////////////////////////////////////
String *_(ReadToEnd)()
{
	String *result = NEW (String) ("");

	String *line;

	while ((line = CharStream_ReadLine(this))) {
		if (result->length) String_Append(result, '\n');

		String_Concat(result, line);
	}

	DELETE (this);

	return result;
}

#undef TYPENAME

#endif
