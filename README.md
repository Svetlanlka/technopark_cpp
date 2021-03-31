# technopark_cpp
Ocheretnaya Svetlana, IU5-45B. TP. CPP
Вариант #69
В вашем распоряжении директория с 500 текстовыми файлами, каждый из которых занимает 1 МБ места на диске. Необходимо реализовать последовательную и параллельную программу поиска с использованием нескольких потоков топ-5 файлов по текстовому запросу. Принцип ранжирования – количество точных вхождений запроса в файл.

ОБРАБОТКА 500 файлов по 1 МБ. Среднее время работы: <br/>
1 ПОТОК: 841.48051 сек. <br/>
8 ПОТОКОВ: 821.010010 сек. <br/>
БЕЗ ПОТОКОВ: 778.936340 сек.

Замечание: 
1. С увеличением колличества потоков в разумном колличестве скорость обработки растет. 
2. С увеличением колличества обрабатываемых данных разница между потоковой и обычной, последовательной
обработкой становится меньше. Однако при тестировании на малом объеме данных, следует заметить,
   что создание потоков идет в ущерб процессорному времени.