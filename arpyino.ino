void setup() {
  Serial.begin(115200);
}

String x;

void loop() {
  if (Serial.available() > 0) {
    x = Serial.readString();
    x.trim();

    if (x.startsWith("PM,")) {
      int commaIndex = x.indexOf(',');
      int colonIndex = x.indexOf(':');

      // Converte pino e valor para int
      int pino = x.substring(commaIndex + 1, colonIndex).toInt();
      String valor = x.substring(colonIndex + 1);
      valor.toLowerCase();  // Converte para letras minúsculas

      if (valor == "output") {
        pinMode(pino, OUTPUT);
      } else if (valor == "input") {
        pinMode(pino, INPUT);
      }
    }

    if (x.startsWith("AW,")) {
      int commaIndex = x.indexOf(',');
      int colonIndex = x.indexOf(':');

      int pino = x.substring(commaIndex + 1, colonIndex).toInt();
      int valor = x.substring(colonIndex + 1).toInt();
      analogWrite(pino, valor);
    }

    if (x.startsWith("DW,")) {
      int commaIndex = x.indexOf(',');
      int colonIndex = x.indexOf(':');

      int pino = x.substring(commaIndex + 1, colonIndex).toInt();
      int valor = x.substring(colonIndex + 1).toInt();
      digitalWrite(pino, valor);
    }

    if (x.startsWith("AR,")) {
      int commaIndex = x.indexOf(',');
      int colonIndex = x.indexOf(':');

      int pino = x.substring(commaIndex + 1, colonIndex).toInt();
      int leitura = analogRead(pino);  // Lê o valor analógico
      Serial.println(String(leitura));         // Envia o valor de volta
    }

    if (x.startsWith("DR,")) {
      int commaIndex = x.indexOf(',');
      int colonIndex = x.indexOf(':');

      int pino = x.substring(commaIndex + 1, colonIndex).toInt();
      int leitura = digitalRead(pino);  // Lê o valor digital
      Serial.print(String(leitura));          // Envia o valor de volta
    }

    // Limpa o buffer serial
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}
