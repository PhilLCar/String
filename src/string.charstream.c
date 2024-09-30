#include <string.charstream.h>

#define TYPENAME CharStream

////////////////////////////////////////////////////////////////////////////////
String *_(getline)()
{
	String *line = NEW (String) ("");
	char c;

	while((c = CharStream_get(this)) != '\n' && c != EOF) {
    if (c != '\r') String_append(line, c); 
  } 

	if (c == EOF && !line->length) {
		DELETE (line);
	}

  return line;
}

////////////////////////////////////////////////////////////////////////////////
String *_(readline)()
{
	String *line = NEW (String) ("");
	char c;

	while((c = CharStream_read(this)) != '\n' && c != EOF) {
    if (c != '\r') String_append(line, c); 
  } 

	if (c == EOF && !line->length) {
		DELETE (line);
	}

  return line;
}