#include <string.charstream.h>

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

#undef TYPENAME
