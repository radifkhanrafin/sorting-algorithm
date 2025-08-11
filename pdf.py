from fpdf import FPDF

# Create PDF
pdf = FPDF()
pdf.set_auto_page_break(auto=True, margin=15)
pdf.add_page()

# Title
pdf.set_font("Arial", 'B', 16)
pdf.cell(0, 10, "Merge Sort and Quick Sort", ln=True, align='C')

# Merge Sort
pdf.set_font("Arial", 'B', 14)
pdf.cell(0, 10, "1. Merge Sort", ln=True)

pdf.set_font("Arial", 'B', 12)
pdf.cell(0, 10, "Algorithm:", ln=True)
pdf.set_font("Arial", '', 12)
pdf.multi_cell(0, 10, 
    "1. If the array has more than one element:\n"
    "   a. Divide the array into two halves.\n"
    "   b. Recursively sort both halves.\n"
    "   c. Merge the two sorted halves into one sorted array."
)

pdf.set_font("Arial", 'B', 12)
pdf.cell(0, 10, "C++ Code:", ln=True)
pdf.set_font("Courier", '', 10)
merge_sort_code = '''
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftSubArray[n1], rightSubArray[n2];
    for (int i = 0; i < n1; i++)
        leftSubArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightSubArray[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftSubArray[i] <= rightSubArray[j]) {
            arr[k] = leftSubArray[i];
            i++;
        } else {
            arr[k] = rightSubArray[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftSubArray[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = rightSubArray[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
'''
pdf.multi_cell(0, 5, merge_sort_code)

# Quick Sort
pdf.add_page()
pdf.set_font("Arial", 'B', 14)
pdf.cell(0, 10, "2. Quick Sort", ln=True)

pdf.set_font("Arial", 'B', 12)
pdf.cell(0, 10, "Algorithm:", ln=True)
pdf.set_font("Arial", '', 12)
pdf.multi_cell(0, 10, 
    "1. If the array has more than one element:\n"
    "   a. Select a pivot element.\n"
    "   b. Partition the array so that elements smaller than pivot are left, larger are right.\n"
    "   c. Recursively apply Quick Sort to left and right partitions."
)

pdf.set_font("Arial", 'B', 12)
pdf.cell(0, 10, "C++ Code:", ln=True)
pdf.set_font("Courier", '', 10)
quick_sort_code = '''
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
'''
pdf.multi_cell(0, 5, quick_sort_code)

# Save PDF
pdf_path = "/mnt/data/Merge_Sort_Quick_Sort_Algorithm_and_Code.pdf"
pdf.output(pdf_path)

pdf_path
