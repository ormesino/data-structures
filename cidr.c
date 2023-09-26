#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct IP
{
  int bytes[4];
  int bin[32];
  char info[250];
  int cidr; 
  int matches;
  bool matchFlag;
} IP;

void convertToBinary(IP *address)
{
  int i, j;
  int content[3];
  int count = 31;

  for (i = 0; i < 4; i++)
    content[i] = address->bytes[i];

  for (i = 3; i >= 0; i--)
  {
    for (j = 0; j < 8; j++)
    {
      if (content[i] % 2 != 0)
        address->bin[count] = 1;
      else
        address->bin[count] = 0;
      content[i] = content[i] / 2;
      count = count - 1;
    }
  }
}

void checkIP(IP *end, IP *test)
{
  int i;
  end->matches = 0;
  end->matchFlag = false;
  for (i = 0; i < end->cidr; i++)
  {
    if (end->bin[i] == test->bin[i])
      end->matches++;
    else
      break;
  }

  if (end->cidr == end->matches)
    end->matchFlag = true;
}

int main(void)
{
  IP *addresses;           
  IP test, lastMatch; 
  int i, j, qntyIPs;  
                       
  scanf("%d", &qntyIPs);
  addresses = (IP *)calloc(qntyIPs, sizeof(IP));
  if (!addresses)
    return "[ERROR] Erro na alocação de memória.";

  for (i = 0; i < qntyIPs; i++)
  {
    scanf("%d.%d.%d.%d/%d ", &addresses[i].bytes[0], &addresses[i].bytes[1], &addresses[i].bytes[2], &addresses[i].bytes[3], &addresses[i].cidr);
    fgets(addresses[i].info, 250, stdin);
    addresses[i].matches = 0;       
    convertToBinary(&addresses[i]);
  }

  while (!feof(stdin))
  {
    if (scanf("%d.%d.%d.%d", &test.bytes[0], &test.bytes[1], &test.bytes[2], &test.bytes[3]) == 4)
    {
      convertToBinary(&test);

      for (i = 0; i < qntyIPs; i++)
        checkIP(&addresses[i], &test);
       
      lastMatch = addresses[0];
      for (i = 0; i < qntyIPs; i++)
      {
        if (addresses[i].matchFlag == true)
        {
          lastMatch = addresses[i];
          if (addresses[i].matchFlag == true || addresses[i].matches > lastMatch.matches)
            lastMatch = addresses[i];
        }
      }

      printf("%d.%d.%d.%d %s", test.bytes[0], test.bytes[1], test.bytes[2], test.bytes[3], lastMatch.info);
      j++;

      if (feof(stdin))
        break;
    }
  }

  return 0;
}