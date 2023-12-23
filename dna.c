#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100
#define NUMPROTEINS 64

// MY MAIN FUNCATION 
//Prototypes 
bool isBasePair(char neu1, char neu2);
bool isItaDnaSequence (char strand1 [SIZE], char strand2 [SIZE]);
void reverse (char aStrand [SIZE], char reversed[SIZE]);
void complementIt (char aStrand [SIZE]);
bool isItPalindrome (char aStrand [SIZE]);
bool isStrandDnaPalindrome (char aStrand [SIZE]);
int howMany (char aStrand [SIZE], char neu);
void dnaToMrna (char aSeq [SIZE], char mRNA [SIZE]);
void translateDnaToMrnaProteins (char aSeq [SIZE]);
char getCode(char protein[3]);


int main() {
    bool isBasePairResult;
    bool isItPalindromeResult;
    char reversedStrand[SIZE];
    char mrnaResult[SIZE];
    char aSeq[SIZE], mRNA[SIZE];
    
    // Test isBasePair function
    printf("Testing isBasePair function:\n");
    isBasePairResult = isBasePair('A', 'T');  // Expected result: true
    printf("Result of isBasePair('A', 'T'): %d\n", isBasePairResult);
    
    isBasePairResult = isBasePair('A', 'C');  // Expected result: false
    printf("Result of isBasePair('A', 'C'): %d\n", isBasePairResult);

    // Test isItPalindrome function
    printf("Testing isItPalindrome function:\n");
    isItPalindromeResult = isItPalindrome("madam");  // Expected result: true
    printf("Result of isItPalindrome('madam'): %d\n", isItPalindromeResult);
    
    isItPalindromeResult = isItPalindrome("hello");  // Expected result: false
    printf("Result of isItPalindrome('hello'): %d\n", isItPalindromeResult);

    // Test reverse function
    printf("Testing reverse function:\n");
    char aStrandToReverse[] = "CCAGT";
    reverse(aStrandToReverse, reversedStrand);  // Expected result: "TGACC"
    printf("Reversed strand: %s\n", reversedStrand);

    // Test dnaToMrna function
    printf("Testing dnaToMrna function:\n");
    char dnaSequence[] = "CCAGT";
    dnaToMrna(dnaSequence, mrnaResult);  // Expected result: "GGUCA"
    printf("mRNA: %s\n", mrnaResult);

    // Add more test cases for other functions
    bool isItaDnaSequenceResult;
char strand1[SIZE], strand2[SIZE];

printf("Testing isItaDnaSequence function:\n");
strcpy(strand1, "ATCG");
strcpy(strand2, "TAGC");
isItaDnaSequenceResult = isItaDnaSequence(strand1, strand2);  // Expected result: true
printf("Result of isItaDnaSequence('ATCG', 'TAGC'): %d\n", isItaDnaSequenceResult);

strcpy(strand1, "ATCG");
strcpy(strand2, "ACGT");
isItaDnaSequenceResult = isItaDnaSequence(strand1, strand2);  // Expected result: false
printf("Result of isItaDnaSequence('ATCG', 'ACGT'): %d\n", isItaDnaSequenceResult);

char aStrandToComplement[SIZE];

printf("Testing complementIt function:\n");
strcpy(aStrandToComplement, "ATCG");
complementIt(aStrandToComplement);  // Expected result: "TAGC"
printf("Complemented strand: %s\n", aStrandToComplement);

strcpy(aStrandToComplement, "CGTA");
complementIt(aStrandToComplement);  // Expected result: "GCAT"
printf("Complemented strand: %s\n", aStrandToComplement);

bool isStrandDnaPalindromeResult;
char dnaPalindrome[SIZE], nonDnaPalindrome[SIZE];

printf("Testing isStrandDnaPalindrome function:\n");
strcpy(dnaPalindrome, "ATCGTAGC");
isStrandDnaPalindromeResult = isStrandDnaPalindrome(dnaPalindrome);  // Expected result: true
printf("Is 'ATCGTAGC' a DNA palindrome? %d\n", isStrandDnaPalindromeResult);

strcpy(nonDnaPalindrome, "ATCGGCTA");
isStrandDnaPalindromeResult = isStrandDnaPalindrome(nonDnaPalindrome);  // Expected result: false
printf("Is 'ATCGGCTA' a DNA palindrome? %d\n", isStrandDnaPalindromeResult);

int countResult;
char strandToCount[SIZE];

printf("Testing howMany function:\n");
strcpy(strandToCount, "GGATCC");
countResult = howMany(strandToCount, 'G');  // Expected result: 3
printf("Total 'G' in 'GGATCC': %d\n", countResult);

strcpy(strandToCount, "ACGTA");
countResult = howMany(strandToCount, 'A');  // Expected result: 2
printf("Total 'A' in 'ACGTA': %d\n", countResult);

char dnaSequenceForTranslation[SIZE];

printf("Testing translateDnaToMrnaProteins function:\n");
strcpy(dnaSequenceForTranslation, "ATCGTAGC");
printf("Translating DNA to mRNA and then to proteins for 'ATCGTAGC':\n");
translateDnaToMrnaProteins(dnaSequenceForTranslation);

strcpy(dnaSequenceForTranslation, "CAGTGGCTA");
printf("Translating DNA to mRNA and then to proteins for 'CAGTGGCTA':\n");
translateDnaToMrnaProteins(dnaSequenceForTranslation);


    return 0;
}


// Function to check if two nucleotides form a base pair
bool isBasePair(char neu1, char neu2) {
    return ((neu1 == 'A' && neu2 == 'T') || (neu1 == 'T' && neu2 == 'A') ||
            (neu1 == 'C' && neu2 == 'G') || (neu1 == 'G' && neu2 == 'C'));
}

// Function to check if a given string is a palindrome
bool isItPalindrome(char aStrand[SIZE]) {
    int length = strlen(aStrand);
    int i = 0;
    int j = length - 1;

    while (i < j) {
        if (aStrand[i] != aStrand[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// Function to count the total number of a specific nucleotide in a strand
int howMany(char aStrand[SIZE], char neu) {
    int length = strlen(aStrand);
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (aStrand[i] == neu) {
            count++;
        }
    }

    return count;
}

// Function to convert a DNA sequence into its corresponding mRNA sequence
void dnaToMrna(char aSeq[SIZE], char mRNA[SIZE]) {
    int length = strlen(aSeq);

    for (int i = 0; i < length; i++) {
        char currentChar = aSeq[i];
        switch (currentChar) {
            case 'A':
                mRNA[i] = 'U';
                break;
            case 'T':
                mRNA[i] = 'A';
                break;
            case 'C':
                mRNA[i] = 'G';
                break;
            case 'G':
                mRNA[i] = 'C';
                break;
        }
    }
    mRNA[length] = '\0';
}

// Function to look up the amino acid code for a given mRNA codon
char getCode(char protein[3]) {
    char allProteins[NUMPROTEINS][SIZE] = {
        "GCA", "GCC", "GCG", "GCU", "AGA", "AGG", "CGA", "CGC", "CGG", "CGU",
        "GAC", "GAU", "AAC", "AAU", "UGC", "UGU", "GAA", "GAG", "CAA", "CAG",
        "GGA", "GGC", "GGG", "GGU", "CAC", "CAU", "AUA", "AUC", "AUU", "UUA",
        "UUG", "CUA", "CUC", "CUG", "CUU", "AAA", "AAG", "AUG", "UUC", "UUU",
        "CCA", "CCC", "CCG", "CCU", "AGC", "AGU", "UCA", "UCC", "UCG", "UCU",
        "ACA", "ACC", "ACG", "ACU", "UGG", "UAC", "UAU", "GUA", "GUC", "GUG", "GUU"
    };

    char allCodes[NUMPROTEINS] = {
        'A', 'A', 'A', 'A', 'R', 'R', 'R', 'R', 'R', 'R', 'D', 'D', 'N', 'N', 'C', 'C',
        'E', 'E', 'Q', 'Q', 'G', 'G', 'G', 'G', 'H', 'H', 'I', 'I', 'I', 'L', 'L', 'L', 'L',
        'L', 'L', 'K', 'K', 'M', 'F', 'F', 'P', 'P', 'P', 'P', 'S', 'S', 'S', 'S', 'S', 'S',
        'T', 'T', 'T', 'T', 'W', 'Y', 'Y', 'V', 'V', 'V', 'V'
    };

    for (int i = 0; i < NUMPROTEINS; i++) {
        if (strncmp(protein, allProteins[i], 3) == 0) {
            return allCodes[i];
        }
    }

    return 'Z'; // Indicates an incorrect code - code that doesn't exist in array allCodes
}

// Function to translate a DNA sequence into mRNA and then print the amino acids
void translateDnaToMrnaProteins(char aSeq[SIZE]) {
    int length = strlen(aSeq);
    char mRNA[SIZE];
    
    // Convert DNA to mRNA
    for (int i = 0; i < length; i++) {
        char currentChar = aSeq[i];
        switch (currentChar) {
            case 'A':
                mRNA[i] = 'U';
                break;
            case 'T':
                mRNA[i] = 'A';
                break;
            case 'C':
                mRNA[i] = 'G';
                break;
            case 'G':
                mRNA[i] = 'C';
                break;
        }
    }
    mRNA[length] = '\0';


    printf("DNA: %s\n", aSeq);
    printf("mRNA: %s\n", mRNA);
    printf("Which translates to:\n");

    int mRNA_length = strlen(mRNA);
    for (int i = 0; i < mRNA_length; i += 3) {
        char codon[4] = {mRNA[i], mRNA[i + 1], mRNA[i + 2], '\0'};
        char aminoAcid = getCode(codon);
        printf("%s : %c\n", codon, aminoAcid);
    }
}

int main() {
    char aStrand[SIZE] = "CGTAGGCAT";
    char mRNA[SIZE];

    printf("Is 'A' and 'T' a base pair? %d\n", isBasePair('A', 'T'));

    printf("Is 'CGTAGGCAT' a palindrome? %d\n", isItPalindrome("CGTAGGCAT"));

    printf("Total 'G' in 'GGCCGG': %d\n", howMany("GGCCGG", 'G'));

    dnaToMrna(aStrand, mRNA);
    printf("DNA: %s\n", aStrand);
    printf("mRNA: %s\n", mRNA);

    printf("Translating DNA to mRNA and then to proteins:\n");
    translateDnaToMrnaProteins(aStrand);

    return 0;
}