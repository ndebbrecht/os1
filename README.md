Aufgabe 1 – Implementierung Shell
In der Belegübung haben wir die Shell als Benutzerschnittstelle von UNIX verwendet. Der Nutzer
kann Kommandos eingeben, die vom Betriebssystem ausgeführt werden. Die Shell hat somit die
Funktion eines Kommando-Interpreters. Die verschiedenen Shell-Varianten in UNIX übernehmen
dazu weitere Funktionen: Starten und Stoppen von Prozessen, Handhabung von Platzhaltern
(Wildcards), Handhabung von Umgebungs-Variablen, Verkettung von Prozessen, Ausführung von
Skripten bestehend aus Shell-Kommandos.

Ein Teil dieser Aufgaben soll im Rahmen des Praktikums realisiert werden.

Aufgabenstellung:
Implementieren Sie eine ‚Mini-Shell‘ als C - Programm, das gewisse Aufgaben der Shell übernimmt.
Die von Ihnen implementierte Shell soll mindestens die folgenden Anforderungen erfüllen:

Das Programm gibt einen Prompt bestehend aus User-Name und aktuellem Directory aus
und liest eine Eingabezeile von der Standardeingabe (stdin).
Das Programm erzeugt per fork() einen neuen Kindprozess.
Das Programm startet per Funktion execlp() oder per execvp() das aus der
Benutzereingabe extrahierte Programm im Kindprozess.
Der Elternprozess wartet in der Zwischenzeit mit waitpid() auf das Ende des
Kindprozesses.
Randbedingungen:
Die Kommandos exit und cd sind keine externen Programme, sondern werden direkt von
der Shell bearbeitet (Built-in-Kommandos). Warum ist dies notwendig?
Hinweise:
Zum Einlesen und Auswerten der Eingaben benötigen Sie die Standard-C-Funktionen zur
Verarbeitung von Zeichenketten (z.B. sscanf(), strtok(),...).
Testierung : Do. 27.4. und Do. 4.5.
