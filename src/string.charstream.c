#include <string.charstream.h>

#define TYPENAME CharStream

////////////////////////////////////////////////////////////////////////////////
String *_(getline)()
{
	String *line = NEW (String) ("");
	char c;

	while((c = CharStream_get(this)) != '\n' && !BASE(0)->eos) {
    if (c != '\r') String_append(line, c); 
  } 

	if (BASE(0)->eos && !line->length) {
		DELETE (line);
	}

  return line;
}

////////////////////////////////////////////////////////////////////////////////
String *_(readline)()
{
	String *line = NEW (String) ("");
	char c;

	while((c = CharStream_read(this)) != '\n' && !BASE(0)->eos) {
    if (c != '\r') String_append(line, c); 
  } 

	if (BASE(0)->eos && !line->length) {
		DELETE (line);
	}

  return line;
}