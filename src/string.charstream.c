#include <string.charstream.h>

#define TYPENAME CharStream

////////////////////////////////////////////////////////////////////////////////
String *_(getline)()
{
	return CharStream_readline(this, EOF);
}

////////////////////////////////////////////////////////////////////////////////
String *_(readline)(char esc)
{
	String *line = NEW (String) ("");
	char c;

	while((c = CharStream_get(this)) != '\n' && c != EOF) {
    if (c == esc) c = CharStream_esc(this);
    if (c != '\r') String_append(line, c); 
  } 

	if (c == EOF && !line->length) {
		DELETE (line);
	}

  return line;
}